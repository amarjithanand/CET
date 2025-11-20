import tkinter as tk

def show_text():
    user_text = entry.get()
    result_label.config(text=f"You typed: {user_text}")

root = tk.Tk()
root.title("Simple Tkinter App")
root.geometry("300x200")

label = tk.Label(root, text="Enter something:")
label.pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=5)

button = tk.Button(root, text="Show Text", command=show_text)
button.pack(pady=10)

result_label = tk.Label(root, text="")
result_label.pack(pady=10)

root.mainloop()
