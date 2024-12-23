import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

# 目标网页URL
url = 'https://life.djbx.com/col/col1186/index.html'

# 请求头信息
head = {
    'User-Agent':
        'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0'
}

# 发送HTTP请求
response = requests.get(url, headers=head)

# 解析HTML内容
soup = BeautifulSoup(response.text, 'html.parser')

# 找到所有tr元素
tr_tags = soup.find_all('tr')

# 筛选出第二个td中包含“终身寿险”的tr
product_tr_tags = [tr for tr in tr_tags if
                   tr.find('td', string='终身寿险') or tr.find_all('td')[1] == tr.find('td', string='终身寿险')]

# 遍历每个符合条件的tr
for product_tr in product_tr_tags:
    # 找到第五个td元素
    product_td = product_tr.find_all('td')[4]
    # 找到第一个div
    product_div = product_td.find('div')
    # 找到第一个div中的第一个ul
    product_div_div_ul = product_div.find('ul')
    # 找到第一个ul中的第一个li
    product_div_div_ul_first_li = product_div_div_ul.find('li')
    # 找到第一个li中的第一个a
    product_div_div_ul_first_li_a = product_div_div_ul_first_li.find('a')
    # 打印a标签的href属性
    print(product_div_div_ul_first_li_a['href'])