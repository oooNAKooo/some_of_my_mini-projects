import os
import sys
from pyfiglet import Figlet
from tqdm import tqdm
import requests
import folium
import ipaddress

SAVE_MAPS_DIR = 'save_maps'


def is_valid_ip(ip):
    try:
        ipaddress.ip_address(ip)
        return True
    except ValueError:
        return False


def get_info_by_IP(ip):
    try:
        response = requests.get(url=f'http://ip-api.com/json/{ip}').json()
        if response['status'] == 'fail':
            print('Введен некорректный IP-адрес. Попробуйте еще раз.')
            main()
        data = {
            '[IP]': response.get('query'),
            '[Страна]': response.get('country'),
            '[Город]': response.get('city'),
            '[Индекс почты]': response.get('zip'),
            '[Провайдер]': response.get('isp'),
            '[Широта]': response.get('lat'),
            '[Долгота]': response.get('lon')
        }

        for key, value in data.items():
            if value is None or value == '':
                value = 'NO_INFO'
            print(f'{key}: {value}')

        create_map(response.get('lat'), response.get('lon'), response.get('query'))

    except requests.exceptions.ConnectionError:
        print('Проверьте подключение к интернету!')


def get_info_by_place(name):
    try:
        url = f"https://nominatim.openstreetmap.org/search?q={name}&format=json&limit=1"
        with tqdm(desc="Идет поиск", unit=" запрос", ncols=100) as progress_bar:
            response = requests.get(url)
            data = response.json()
            progress_bar.update(1)
        if data:
            place = data[0]
            print(f'Название: {place.get("display_name")}')
            print(f'Широта: {place.get("lat")}')
            print(f'Долгота: {place.get("lon")}')
        else:
            print('Информация о данном месте не найдена.')
    except Exception as e:
        print(f'Произошла ошибка: {e}')


def create_map(latitude, longitude, filename):
    map_victim = folium.Map(location=[latitude, longitude])
    save_dir = os.path.join(SAVE_MAPS_DIR, filename)
    os.makedirs(save_dir, exist_ok=True)
    save_path = os.path.join(save_dir, f'{filename}.html')
    map_victim.save(save_path)
    print(f'Карта сохранена: {save_path}')


def print_help():
    print('Доступные команды:')
    print('[1] - "ip" - поиск информации по IP-адресу;')
    print('[2] - "place" - поиск информации о географическом объекте;')
    print('[0] - "exit" - выход из программы.')


def main():
    preview = Figlet(font='slant')
    print(preview.renderText('FAST PARS'))

    print_help()

    while True:
        command = input('Введите команду: ').lower()

        if command == 'ip' or command == '1':
            ip = input('Введите IP жертвы: ')
            if not is_valid_ip(ip):
                print('Введен некорректный IP-адрес. Попробуйте еще раз.')
                continue
            get_info_by_IP(ip)
        elif command == 'place' or command == '2':
            name = input('Введите название места: ')
            get_info_by_place(name)
        elif command == 'help' or command == 'h':
            print_help()
        elif command == 'exit' or command == '0':
            last_mes = Figlet(font='slant')
            print(last_mes.renderText('CLOSING'))
            sys.exit()
        else:
            print('Неверная команда. Попробуйте снова.')
            print_help()


if __name__ == '__main__':
    main()
