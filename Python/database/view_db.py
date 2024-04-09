import tkinter as tk
from tkinter import ttk, messagebox
import sqlite3

class ViewWindow(tk.Toplevel):
    def __init__(self, entity):
        super().__init__()
        self.entity = entity
        self.title(f"Просмотр таблицы {entity}")

        # Создаем древовидный виджет для отображения таблицы
        self.tree = ttk.Treeview(self)
        self.tree.pack(expand=True, fill=tk.BOTH)

        # Создаем вертикальный скроллбар
        scrollbar = ttk.Scrollbar(self, orient="vertical", command=self.tree.yview)
        scrollbar.pack(side="right", fill="y")

        self.tree.configure(yscrollcommand=scrollbar.set)

        # Получаем данные из таблицы
        self.get_data(entity)

        # Добавляем кнопку "Очистить"
        clear_button = tk.Button(self, text="Очистить", command=lambda: self.clear_table(entity))
        clear_button.pack(pady=10)

    def get_data(self, entity):
        # Подключаемся к базе данных
        connection = sqlite3.connect("my_database.db")
        cursor = connection.cursor()

        # Выполняем запрос к таблице
        cursor.execute(f"SELECT * FROM {entity}")

        # Получаем заголовки столбцов
        columns = [description[0] for description in cursor.description]

        # Заполняем заголовки столбцов в древовидном виджете
        self.tree["columns"] = columns
        self.tree.heading("#0", text=entity)
        for col in columns:
            self.tree.heading(col, text=col)
            self.tree.column(col, anchor=tk.CENTER)

        # Очищаем дерево перед заполнением
        self.tree.delete(*self.tree.get_children())

        # Получаем количество записей в таблице
        row_count = len(cursor.fetchall())

        # Начинаем нумерацию с 1, если таблица пуста
        if row_count == 0:
            row_num = 1
        else:
            row_num = row_count + 1

        # Заполняем данные из таблицы
        cursor.execute(f"SELECT * FROM {entity}")
        for row in cursor.fetchall():
            self.tree.insert(parent="", index="end", iid=row_num, values=(*row,))
            row_num += 1

        # Закрываем соединение с базой данных
        connection.close()

    def clear_table(self, entity):
        try:
            # Подключаемся к базе данных
            connection = sqlite3.connect("my_database.db")
            cursor = connection.cursor()

            # Выполняем запрос на удаление всех записей из выбранной таблицы
            cursor.execute(f"DELETE FROM {entity}")

            # Применяем изменения
            connection.commit()
            connection.close()

            # Очищаем отображение таблицы
            for row in self.tree.get_children():
                self.tree.delete(row)

            messagebox.showinfo("Успех", f"Все записи из таблицы {entity} успешно удалены!")
        except Exception as e:
            messagebox.showerror("Ошибка", f"Не удалось очистить таблицу: {e}")
