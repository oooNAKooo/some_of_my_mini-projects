import tkinter as tk
from tkinter import messagebox

# Функции для обработки выбора в меню
def convert_video():
    messagebox.showinfo("Конвертировать видео", "Вы выбрали конвертировать видео")

def convert_photo():
    messagebox.showinfo("Конвертировать фото", "Вы выбрали конвертировать фото")

def exit_app():
    if messagebox.askokcancel("Выход", "Вы уверены, что хотите выйти?"):
        root.destroy()

# Создаем главное окно
root = tk.Tk()
root.title("Меню приложения")

# Создаем меню
menu = tk.Menu(root)
root.config(menu=menu)

# Создаем пункты меню
file_menu = tk.Menu(menu)
menu.add_cascade(label="Меню", menu=file_menu)
file_menu.add_command(label="Конвертировать видео", command=convert_video)
file_menu.add_command(label="Конвертировать фото", command=convert_photo)
file_menu.add_separator()
file_menu.add_command(label="Выход", command=exit_app)

# Запускаем главный цикл приложения
root.mainloop()
