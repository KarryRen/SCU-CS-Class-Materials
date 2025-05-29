#导库
#将爬取到的数据存入csv文件（电影名、导演、主演、年份、电影类型、评分、评语）(done)
#将电影海报按顺序编号（1.jpg~250.jpg）下载存储到名为images的文件夹下(done)
#按照年份，用合适的图表统计每一年的电影数量（除此之外可以随意统计其他的）
from bs4 import BeautifulSoup
import requests
import re
import csv
import xlwt
#模拟浏览器发起请求
datalist = []
def main():
    savepath = "./douban_top250.csv"
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36'
        }
    for i in range(0, 250, 25):
        url="https://movie.douban.com/top250?start="+str(i)
        response = requests.get(url, headers=headers)
        #print(response)
        get_pic(i, response)
        get_data(response)
        '''for i in range(0,len(datalist)):
            print(datalist[i])
        '''
        save_data(savepath)

#每个电影都属于item类
#获取图片url->根据url下载
def get_pic(i, response):
    # 解析爬取数据
    bs = BeautifulSoup(response.text, 'html.parser')
    pics=bs.find_all('div', 'pic')
    links=[]
    for pic in pics:
        #定位pics下方的img标签，获取src中的url
        links.append(pic.find('img').attrs['src'])
    #for link in links:
        #print(link)
    #print(len(links))#爬一页的
    for j in range(len(links)):
        #根据url下载图片
        path='./imgs/{}.jpg'.format(i+j+1)
        res=requests.get(links[j])
        with open(path, 'wb') as f:#定义一个文件操作对象
            f.write(res.content)
            print('{}.jpg has been download'.format(i+j+1))

#获取各个标签里面的电影信息
def get_data(response):
    soup=BeautifulSoup(response.text, 'html.parser')
    for item in soup.find_all('div', class_='item'):
        data = []
        data.append(item.find_all(class_='title')[0].get_text())#电影名
        para=(item.find_all('p')[0])
        para=str(para)
        para = para.replace('<p class="">', '')
        para = para.replace('</p>', '')
        para = para.replace('<br/>','')
        para = para.replace(' ', '')
        para = para.replace('\n', '')
        para = para.replace('\xa0', ':')
        pattern1 = re.compile(r':+')
        para = para.replace('/', '')
        para = re.sub(pattern1, ':', para)
        char_to_insert = ':'
        # 使用正则表达式找到要插入字符的位置
        pattern2 = r'\d{4}'
        match = re.search(pattern2, para)
        position = match.start()
        para = para[:position] + char_to_insert + para[position:]
        pattern3= r'主...'
        para = re.sub(pattern3, "主演:...", para)
        if para.find('主演:...')==-1:
            para = para+'主演:...'
        data.append(para.split(':')[1])#导演
        data.append(para.split(':')[3])#主演
        data.append(para.split(':')[4])#时间
        if len(para.split(':')) >= 7:
            data.append(para.split(':')[6])#类型
        else:
            data.append("")
        data.append(item.find_all(class_='rating_num')[0].get_text())  # 评分
        data.append(item.find_all(class_='inq')[0].get_text() if len(item.find_all(class_='inq')) == 1 else "")#评语
        datalist.append(data)

def save_data(savepath):
    row = ['电影名', '导演', '主演', '年份', '电影类型', '评分', '评语']
    with open(savepath, 'w', encoding='utf-8-sig', newline='') as f:
        writer=csv.writer(f)
        writer.writerow(row)
        for i in range(0, len(datalist)):
            writer.writerow(datalist[i])

if __name__ == '__main__':
    main()
