
import java.util.Scanner;

class Authentication {

    static final String USERNAME = "username";
    static final String PASSWORD = "password";
    
    public static void main(String[] args) {
        
        try {

            Scanner sc = new Scanner(System.in);
            System.out.print("Enter username: ");
            String username = sc.next();
            sc.nextLine();
            
            if (!username.equals(USERNAME)) {
                sc.close();
                throw new InvalidUsernameException();
            } 
            
            System.out.print("Enter password: ");
            String password = sc.next();
            sc.nextLine();
            sc.close();

            if (!password.equals(PASSWORD)) throw new InvalidPasswordException();
            
            System.out.println("Logged In!");

        } catch (InvalidUsernameException | InvalidPasswordException e) {
            e.printStackTrace();
        } catch (Exception e) {
            return;
        }
    }

}

class InvalidUsernameException extends RuntimeException {

    InvalidUsernameException() {

        super("Invalid Username!"); 

    }

}

class InvalidPasswordException extends  RuntimeException {

    InvalidPasswordException() {

        super("Invalid Password!");

    }

}

