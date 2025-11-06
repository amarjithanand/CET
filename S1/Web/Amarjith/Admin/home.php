<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "students";

    $conn = mysqli_connect($servername,$username,$password,$dbname);
    $user = $_POST['username'];
    $pass = $_POST['password'];

    $result = mysqli_query($conn,"SELECT * FROM login");
    if (mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        if($row['username']==$user && $row['password'] == $pass){
            echo "<frameset cols='20%,80%'>";
            echo "<frame src='menu.php'></frame>";
            echo "<frame src='register.php' name='mainFrame'></frame></frameset>";
        }
        else{
            echo "<h1>INVALID USERNAME AND PASSWORD</h1>";
        }
    }
    ?>
</html>