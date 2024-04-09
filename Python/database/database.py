import sqlite3

def create_database():
    # Подключаемся к базе данных (если она существует) или создаем новую базу данных
    connection = sqlite3.connect("my_database.db")
    cursor = connection.cursor()

    # Создаем таблицу "Магазин"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Магазин (
                        ID_магазина INTEGER PRIMARY KEY AUTOINCREMENT,
                        Адрес TEXT,
                        Время_работы TEXT,
                        Тип_оплаты TEXT
                    )''')

    # Создаем таблицу "Сотрудник"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Сотрудник (
                        ID_сотрудника INTEGER PRIMARY KEY,
                        ФИО TEXT,
                        Номер_телефона TEXT,
                        Паспорт_ID TEXT
                    )''')

    # Создаем таблицу "Покупатель"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Покупатель (
                        ID_покупателя INTEGER PRIMARY KEY,
                        ФИО TEXT,
                        Номер_телефона TEXT,
                        Email TEXT
                    )''')

    # Создаем таблицу "Товар"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Товар (
                        ID_товара INTEGER PRIMARY KEY,
                        Название TEXT,
                        Тип_упаковки  TEXT,
                        Цена INTEGER
                    )''')

    # Создаем таблицу "Импортер"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Импортер (
                        ID_импортера INTEGER PRIMARY KEY,
                        Организация  TEXT,
                        Номер_договора INTEGER,
                        Страна_поставки TEXT
                    )''')

    # Создаем таблицу "Склад"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Склад (
                        ID_склада INTEGER,
                        Площадь_склада INTEGER,
                        Тип_склада TEXT,
                        Номер_склада TEXT
                    )''')

    # Создаем таблицу "Чек"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Чек (
                        Товар_ID INTEGER,
                        Сотрудник_ID INTEGER,
                        Покупатель_ID INTEGER,
                        FOREIGN KEY (Покупатель_ID) REFERENCES Покупатель(ID_покупателя),
                        FOREIGN KEY (Сотрудник_ID) REFERENCES Сотрудник(ID_сотрудника),
                        FOREIGN KEY (Товар_ID) REFERENCES Товар(ID_товара)
                    )''')

    # Создаем таблицу "Логистика"
    cursor.execute('''CREATE TABLE IF NOT EXISTS Логистика (
                        Дата_поставки TEXT PRIMARY KEY,
                        Товар_логистики_ID INTEGER,
                        Импортер_логистики_ID INTEGER,
                        FOREIGN KEY (Товар_логистики_ID) REFERENCES Товар(ID_товара),
                        FOREIGN KEY (Импортер_логистики_ID) REFERENCES Импортер(ID_импортера)
                    )''')


    # Сохраняем изменения и закрываем соединение
    connection.commit()
    connection.close()

if __name__ == "__main__":
    create_database()
    print("База данных успешно создана!")
