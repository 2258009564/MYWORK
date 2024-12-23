"""
题目：构建一个简单的文本编辑器
要求：设计一个TextEditor类
用于处理文本的添加、删除和显示功能
构造函数：__init__方法初始化一个空字符串作为文档内容
方法：add_text(text)：在文档末尾添加文本
delete_text(start, end)：删除从start位置到end位置的文本（包含end）
如果end超出当前文本长度，则删除到文档末尾
display_text()：显示当前文档的全部内容
额外挑战：实现一个文本编辑器的命令行界面
使用while循环不断接收用户的命令（如添加文本、删除文本或显示文本）
并调用相应的方法执行操作，直到用户输入特定的退出命令。
"""


class TextEditor:
    def __init__(self):
        self.text = ''

    def add_text(self, word):
        self.text += word
        return self.text

    def delete_text(self, start, end):
        try:
            start_index = self.text.index(start)
            end_index = self.text.index(end) + len(end)
            self.text = self.text[:start_index] + self.text[end_index:]
        except ValueError:
            print("指定的开始或结束词不在文本中，请重新输入。")
        return self.text


print('欢迎使用文本编辑器')
type_message = f'''
你希望怎么处理文本？ 1. 在文本末尾添加内容 2. 在文本中间删除内容 PS：按q退出:
'''
print('已为您创建一个新文本')

user_type = TextEditor()
type_msg = input(type_message)
while type_msg not in ['Q', 'q']:
    if type_msg == '1':
        user_type.add_text(input('输入你想添加的文本: '))
    elif type_msg == '2':
        user_type.delete_text(input('你想从哪个词开始删除文本：'), input('到哪里结束： '))
    else:
        print('请输入一个有效的选项')

    if user_type.text != '':
        print(f'''当前文本：{user_type.text}''')
    else:
        print('当前文本为空')
    type_msg = input(type_message)

print('谢谢使用')
