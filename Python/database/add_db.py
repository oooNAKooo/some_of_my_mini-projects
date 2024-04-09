import tkinter as tk
import sqlite3
from tkinter import messagebox

class AddWindow:
    def __init__(self, entity):
        self.entity = entity
        self.window = tk.Toplevel()
        self.window.title(f"Добавление записи в {entity}")
        self.fields = {}
        self.create_input_fields()

    def create_input_fields(self):
        # Получаем список столбцов таблицы из базы данных
        connection = sqlite3.connect("my_database.db")
        cursor = connection.cursor()
        cursor.execute(f"PRAGMA table_info({self.entity})")
        columns_info = cursor.fetchall()
        connection.close()

        # Создаем поля для ввода данных, исключая столбец ID (если он есть)
        fields_info = {info[1]: info[1] for info in columns_info if not info[1].startswith("ID")}
        for field, label_text in fields_info.items():
            label = tk.Label(self.window, text=label_text)
            label.pack()
            entry = tk.Entry(self.window)
            entry.pack()
            self.fields[field] = entry

        # Создаем кнопку "Добавить запись"
        button = tk.Button(self.window, text="Добавить запись", command=self.add_record_to_database)
        button.pack()

    def add_record_to_database(self):
        # Получаем значения из полей ввода
        values = {field: entry.get() for field, entry in self.fields.items()}

        # Выполняем запрос на добавление записи в базу данных
        try:
            connection = sqlite3.connect("my_database.db")
            cursor = connection.cursor()
            columns = ', '.join(values.keys())
            placeholders = ', '.join(['?' for _ in values])
            sql = f"INSERT INTO {self.entity} ({columns}) VALUES ({placeholders})"
            cursor.execute(sql, tuple(values.values()))
            connection.commit()
            connection.close()
            messagebox.showinfo("Успех", "Запись успешно добавлена в базу данных!")
            self.window.destroy()
        except Exception as e:
            messagebox.showerror("Ошибка", f"Не удалось добавить запись: {e}")
