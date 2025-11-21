<?php
session_start();
include "connection.php";

// if not logged in → redirect
if(!isset($_SESSION['username'])){
    header("Location: login.php");
    exit();
}

$username = $_SESSION['username'];

// fetch student details + marks
$sql = "SELECT students.roll, students.name, students.address, students.phone,
               students.username, marks.english, marks.science, marks.maths, marks.total
        FROM students
        INNER JOIN marks ON students.roll = marks.roll
        WHERE students.username = '$username'";

$result = mysqli_query($conn, $sql);
$data = mysqli_fetch_assoc($result);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Home</title>
</head>
<body>

<h2>Your Details</h2>

<table border="1" cellpadding="8">

    <tr>
        <th>Roll Number</th>
        <td><?php echo $data['roll']; ?></td>
    </tr>

    <tr>
        <th>Name</th>
        <td><?php echo $data['name']; ?></td>
    </tr>

    <tr>
        <th>Address</th>
        <td><?php echo $data['address']; ?></td>
    </tr>

    <tr>
        <th>Phone</th>
        <td><?php echo $data['phone']; ?></td>
    </tr>

    <tr>
        <th>Username</th>
        <td><?php echo $data['username']; ?></td>
    </tr>

    <tr>
        <th>English</th>
        <td><?php echo $data['english']; ?></td>
    </tr>

    <tr>
        <th>Science</th>
        <td><?php echo $data['science']; ?></td>
    </tr>

    <tr>
        <th>Maths</th>
        <td><?php echo $data['maths']; ?></td>
    </tr>

    <tr>
        <th>Total</th>
        <td><?php echo $data['total']; ?></td>
    </tr>

</table>

</body>
</html>
