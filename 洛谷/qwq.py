import requests
from bs4 import BeautifulSoup
def getIPList(url="http://31f.cn/http-proxy/"):
    proxies = []
    headers = {
        'User_Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.101 Safari/537.36',
    }

    res = requests.get(url, headers=headers)

    soup = BeautifulSoup(res.text, 'lxml')

    ip_list = soup.select("body > div > table.table.table-striped > tr > td:nth-of-type(2)")
    port_list = soup.select("body > div > table.table.table-striped > tr > td:nth-of-type(3)")

    for i in range(len(port_list)):
        proxies.append(ip_list[i].text + ":" + port_list[i].text)

    return proxies

IPs = getIPList()
#print(IPs)
user_agents = [
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.79 Safari/537.36 Edge/14.14393",
        "Mozilla/5.0 (Windows NT 6.3; Trident/7.0; rv:11.0) like Gecko",
        "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36",
        "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:50.0) Gecko/20100101 Firefox/50.0",
        "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36 OPR/42.0.2393.94",
         "Mozilla/5.0 (Linux; Android 5.1.1; Nexus 6 Build/LYZ28E) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.23 Mobile Safari/537.36",
          "Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B143 Safari/601.1",
          "Mozilla/5.0 (Linux; U; Android 4.0.3; zh-cn; M032 Build/IML74K) AppleWebKit/533.1 (KHTML, like Gecko)Version/4.0 MQQBrowser/4.1 Mobile Safari/533.1",
          "MQQBrowser/38 (iOS 4; U; CPU like Mac OS X; zh-cn)",
          "Mozilla/5.0 (Windows Phone 10.0; Android 4.2.1; Microsoft; Lumia 950) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2486.0 Mobile Safari/537.36 Edge/14.14263"
]
for i in range(len(IPs)):
    print("开始请求")
    user_agent = random.choice(user_agents)
    proxy = IPs[i]
    res = requests.get(blog_url, headers={'user_agent': user_agent}, proxies={'http': proxy})
    print(user_agent + '\t' + proxy, end='\t')
    print(res)
    print("请求结束，准备下一次请求......")
    time.sleep(10)