class publisher:
    def __init__(self,name):
        self.__name = name
        print("Parent Class Constructor Invoked!!")
    def display(self):
        print(f"Author Name : {self.__name}")

class Book(publisher):
    def __init__(self,title, name,price):
        super().__init__(name)
        self.__title = title
        self.__price = price
        print("Child Class Constructor Invoked!!")
    
    def display(self):
        print("Book Details :")
        print(f"Book Name : {self.__title}\nPrice of the Book : {self.__price:.2f}")
        super().display()
    
bookName = input("Enter the Book Name :")
authorName = input("Enter the Author Name :")
price = float(input("Enter the price of the book :"))
ob1 = Book(bookName,authorName,price)
ob1.display()