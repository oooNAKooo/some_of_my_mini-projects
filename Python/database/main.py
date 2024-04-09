# main.py
import tkinter as tk
from delete_db import delete_record_window
from add_db import AddWindow
from view_db import ViewWindow  # Импортируем новое окно для просмотра таблицы

def create_entity_window(entity):
    # Создаем новое окно для работы с выбранной сущностью
    entity_window = tk.Toplevel(root)
    entity_window.title(entity)

def create_operation_window(entity):
    # Создаем новое окно для операций
    operation_window = tk.Toplevel(root)
    operation_window.title(entity)
    operation_window.geometry("400x300")

    # Создаем фрейм для кнопок
    button_frame = tk.Frame(operation_window)
    button_frame.pack(pady=30)

    # Создаем кнопки для операций
    operations = ["Добавить", "Просмотреть", "Удалить"]
    for operation in operations:
        button = tk.Button(button_frame, text=operation, font=("Arial", 18), width=20, height=1)
        button.pack(pady=10)
        # При нажатии на кнопку "Добавить" вызываем функцию для открытия окна добавления записи
        if operation == "Добавить":
            button.config(command=lambda: AddWindow(entity))
        # При нажатии на кнопку "Просмотреть" вызываем функцию для просмотра таблицы
        elif operation == "Просмотреть":
            button.config(command=lambda: view_records(entity))
        # При нажатии на кнопку "Удалить" вызываем функцию для удаления записи
        elif operation == "Удалить":
            button.config(command=lambda: delete_record_window(entity))



def exit_program():
    # Завершаем работу программы
    root.quit()

def view_records(entity):
    # Создаем новое окно для просмотра таблицы
    view_window = ViewWindow(entity)

# Создаем главное окно
root = tk.Tk()
root.title("РАБОТА С:")
root.geometry("1366x768")

# Создаем метку
label = tk.Label(root, text="РАБОТА С:", font=("Arial", 120), pady=30)
label.pack()

# Создаем фрейм для кнопок
button_frame = tk.Frame(root)
button_frame.pack()

# Создаем кнопки для различных сущностей
entities = ["Сотрудник", "Товар", "Покупатель", "Магазин", "Импортер", "Склад", "Чек", "Логистика", "Выход"]
positions = [(0, 0), (0, 1), (0, 2),
             (1, 0), (1, 1), (1, 2),
             (2, 0), (2, 1), (2, 2)]

for entity, pos in zip(entities, positions):
    if entity == "Выход":
        button = tk.Button(button_frame, text=entity, font=("Arial", 18), width=20, height=2, command=exit_program)
    else:
        button = tk.Button(button_frame, text=entity, font=("Arial", 18), width=20, height=2, command=lambda e=entity: create_entity_window(e))
    button.grid(row=pos[0], column=pos[1], padx=10, pady=10)

    # Прикрепляем обработчик события к кнопкам
    if entity != "Выход":
        # Прикрепляем обработчик события к кнопке
        button.config(command=lambda e=entity: create_operation_window(e))

# Запускаем главный цикл обработки событий
root.mainloop()

