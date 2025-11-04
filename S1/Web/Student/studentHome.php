<?php
$roll = $_POST['roll'];
$pass = $_POST['password'];

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "students";

$conn = mysqli_connect($servername,$username,$password,$dbname);

$sql_query = "SELECT Password FROM student WHERE Roll=$roll";
$result = mysqli_query($conn,$sql_query);

if($pass != $result){
    echo "Incorrect password";
}
else{
    echo "Correct Password";
}
