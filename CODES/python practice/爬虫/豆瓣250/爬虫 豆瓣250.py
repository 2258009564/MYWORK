import requests  #requests库用于发送HTTP请求
from bs4 import BeautifulSoup  #BeautifulSoup库用于解析HTML

i = []
for num in range(0, 250, 25):
    url = f'https://movie.douban.com/top250?start={num}'
    head = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0'
    }
    resp = requests.get(url, headers=head)
    html = resp.text
    soup = BeautifulSoup(html, 'html.parser')  #指定html解析器

    all_titles = soup.findAll('span', attrs={'class': 'label-text'})
    for title in all_titles:
        title_string = title.string

        i.append(title_string)  #i是一个空的列表

with open('username.txt', 'w', encoding='utf-8') as f:
    for a in i:
        f.write(a + '\n')
