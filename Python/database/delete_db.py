import sqlite3
import tkinter as tk
from tkinter import messagebox

def delete_record_window(entity):
    # Создаем новое окно для выбора ID записи
    delete_window = tk.Toplevel()
    delete_window.title("Выберите ID")

    # Создаем метку с инструкцией
    label = tk.Label(delete_window, text="Выберите ID записи для удаления:")
    label.pack()

    # Создаем список с доступными ID
    connection = sqlite3.connect("my_database.db")
    cursor = connection.cursor()
    cursor.execute(f"SELECT rowid FROM {entity}")
    record_ids = [row[0] for row in cursor.fetchall()]
    connection.close()

    if not record_ids:
        messagebox.showerror("Ошибка", "Нет доступных записей для удаления.")
        delete_window.destroy()
        return

    # Устанавливаем начальное значение для выбранного ID
    selected_id = tk.StringVar(delete_window)
    selected_id.set(record_ids[0])

    # Создаем выпадающее меню для выбора ID
    id_menu = tk.OptionMenu(delete_window, selected_id, *record_ids)
    id_menu.pack()

    # Функция для удаления записи по выбранному ID
    def delete_selected_record():
        try:
            selected_record_id = selected_id.get()
            if not selected_record_id:
                raise ValueError("Не выбран ID записи")

            # Удаляем запись из базы данных
            connection = sqlite3.connect("my_database.db")
            cursor = connection.cursor()
            cursor.execute(f"DELETE FROM {entity} WHERE rowid = ?", (selected_record_id,))
            connection.commit()
            connection.close()

            messagebox.showinfo("Успех", "Запись успешно удалена из базы данных!")
            delete_window.destroy()
        except ValueError as ve:
            messagebox.showerror("Ошибка", str(ve))
        except Exception as e:
            messagebox.showerror("Ошибка", f"Не удалось удалить запись: {e}")

    # Создаем кнопку для удаления записи
    delete_button = tk.Button(delete_window, text="Удалить", command=delete_selected_record)
    delete_button.pack()
