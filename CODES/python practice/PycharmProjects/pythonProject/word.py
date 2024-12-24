import pandas as pd

def extract_content(cell_value):
    """
    提取单元格内最后一个英文逗号和倒数第二个英文逗号之间的内容。
    """
    if pd.isna(cell_value):
        return cell_value

    # 将单元格内容拆分为部分，以英文逗号为分隔符
    parts = cell_value.split(',')

    # 如果逗号的数量少于两个，则返回空字符串
    if len(parts) < 3:
        return ""

    # 提取倒数第二个和最后一个逗号之间的内容
    return ','.join(parts[-2:-1])


def process_excel(file_path, column_index, output_path):
    """
    处理指定的 Excel 文件，对指定列的内容进行提取，并保存到新的文件。
    """
    # 读取 Excel 文件
    df = pd.read_excel(file_path)

    # 确保指定的列索引在范围内
    if column_index >= len(df.columns):
        raise ValueError(f"列索引 {column_index} 超出范围。")

    # 获取列名
    column_name = df.columns[column_index]

    # 对指定列的每个单元格进行处理
    df[column_name] = df[column_name].apply(extract_content)

    # 将处理后的数据保存到新的 Excel 文件
    df.to_excel(output_path, index=False)


# 示例用法
input_file = "D:\\EdgeDownload\\modified_21年11月.xlsx" # 输入文件路径
output_file = 'C:\\Users\\22580\\Desktop\\modified_21年11月.xlsx' # 输出文件路径
column_index = 2  # 第三列的索引（从0开始）

process_excel(input_file, column_index, output_file)
