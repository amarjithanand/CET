<?php
include "connection.php";

session_start();

if(isset($_POST['login'])){
    $username = $_POST['username'];
    $password = $_POST['password'];

    // check database
    $sql = "SELECT * FROM students WHERE username='$username' AND password='$password'";
    $result = mysqli_query($conn, $sql);

    if(mysqli_num_rows($result) > 0){

        $_SESSION['username'] = $username;

        // if username is admin → go to admin page
        if($username == "admin"){
            header("Location: admin_home.php");
            exit();
        }
        else{
            // normal student login → student home
            header("Location: student_home.php");
            exit();
        }

    } else {
        echo "<script>alert('Invalid username or password');</script>";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Login</title>
</head>
<body>

<h2>Login Page</h2>

<form action="" method="post">
    <label>Username:</label><br>
    <input type="text" name="username" required><br><br>

    <label>Password:</label><br>
    <input type="password" name="password" required><br><br>

    <button type="submit" name="login">Login</button>
</form>

</body>
</html>
