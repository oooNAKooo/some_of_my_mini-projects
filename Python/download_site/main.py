import requests
from bs4 import BeautifulSoup

# ссылка на страницу
url = "https://your_link"

# заголовки
heads = {
    "accept": "your_accept",
    "user-agent": "your_user_agent"
}

req = requests.get(url, headers=heads)
src = req.text

# запись сайта как файл
with open("first_site.html", "w") as file:
    file.write(src)
soup = BeautifulSoup(src, "lxml")
