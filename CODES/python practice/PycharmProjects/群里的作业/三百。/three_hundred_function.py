from docx import Document


def replace_words_in_docx(file_a, word_list, file_c):
    # 加载文件a
    doc = Document(file_a)

    # 遍历文档中的每个段落
    for para in doc.paragraphs:
        # 遍历word_list中的每个单词
        for i in range(len(word_list)):
            # 检查单词是否在段落文本中，包括前后空格或标点符号
            if (' ' + word_list[i] + ' ') in para.text or (' ' + word_list[i] + '.') in para.text or (
                    ' ' + word_list[i] + ',') in para.text:
                # 替换单词为'XXX'
                para.text = para.text.replace(word_list[i], 'XXX')
                # 删除已经替换过的单词，避免重复替换
                del word_list[i]
                break  # 跳出内层循环，继续处理下一个段落

    # 将修改后的文档保存到文件c
    doc.save(file_c)
    print(f"文件 {file_a} 中的单词已替换为 XXX，并保存到文件 {file_c}")


# 调用函数，传入文件路径和要替换的单词列表
replace_words_in_docx('TPO2-5 测试用.docx',
                      ['judicial',
                       'weird',
                       'swamp',
                       'reasonable',
                       'application'],
                      'new_word.docx')

