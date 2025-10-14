class Balance:
    def __init__(self, accNo=None, accName=None, accBalance=0.0):
        self.accNo = accNo
        self.accName = accName
        self.accBalance = float(accBalance)

    def display_info(self):
        print(f"\nAccount Details:\nAccount Number: {self.accNo}\nAccount Holder: {self.accName}\nAccount Balance: ₹{self.accBalance:.2f}")

    def create_acc(self):
        self.accName = input("Enter the name of the account holder: ")
        self.accNo = input("Enter the account number: ")
        self.accBalance = float(input("Enter the initial account balance: "))

    def deposit(self, amount):
        if amount > 0:
            self.accBalance += amount
            print(f"₹{amount:.2f} deposited successfully.")
        else:
            print("Invalid amount.")

    def withdraw(self, amount):
        if 0 < amount <= self.accBalance:
            self.accBalance -= amount
            print(f"₹{amount:.2f} withdrawn successfully.")
        else:
            print("Insufficient balance or invalid amount.")

    def check_balance(self):
        print(f"Current Balance: ₹{self.accBalance:.2f}")


acc = Balance()
op = 1
while(1):
    op =int(input("""Enter the operation to be performed :
          1. Create an account
          2. View the account details
          3. Deposit to the account
          4. Withdraw from the account 
          5. Check balance of the account"""))
    if op ==1:
        acc.create_acc()
    elif op == 2:
        acc.display_info()
    elif op == 3:
        bal = int(input("Enter the balance to Deposit to the account : "))
        acc.deposit(bal)
    elif op == 4:
        bal = int(input("Enter the balance to Withdrawn from the account : "))
        acc.withdraw(bal)
    elif op == 5:
        acc.check_balance()
    else:
        break