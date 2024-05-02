import phonenumbers
from phonenumbers import geocoder, carrier, timezone

help(phonenumbers)

print("Введите номер: ")
phone = input()

print("Короткий индекс страны: ")
code = input()

# Счетчик
count = 0

# Парсим номер
parse_num = phonenumbers.parse(phone)

# Откуда
time_zone = timezone.time_zones_for_number(parse_num)

country = phonenumbers.PhoneNumberMatcher(phone, code)

while count == 0:
    for number in phone:
        if number:
            print(f"Номер {phone} есть в стране с кодом {code}.")
            count = 1
            break
        else:
            print(f"Номер {phone} не существует в стране с кодом {code}.")
            break


print(parse_num)

print(''.join(time_zone))
