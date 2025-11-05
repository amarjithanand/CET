<?php
$name = $_POST['name'];
$roll = $_POST['roll'];
$address = $_POST['address'];
$user = $_POST['username'];
$pass = $_POST['password'];


$servername = "localhost";
$username = "root";
$password = "";
$dbname = "students";

$conn = mysqli_connect($servername,$username,$password,$dbname);

$sql_query = "INSERT INTO student(Roll,Name,Address,Password) VALUES ($roll,'$name','$address','$pass')";
mysqli_query($conn,$sql_query);
$sql_query = "INSERT INTO login VALUES ('$user','$pass')";
mysqli_query($conn,$sql_query);

?>
