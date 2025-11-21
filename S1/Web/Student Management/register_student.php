<?php
include "connection.php";

// ------ FETCH USED ROLL NUMBERS ------
$used = array();
$q = "SELECT roll FROM students";
$res = mysqli_query($conn, $q);

while($row = mysqli_fetch_assoc($res)){
    $used[] = $row['roll'];
}

// ------ REGISTER STUDENT ------
if(isset($_POST['register'])){
    $roll = $_POST['roll'];
    $name = $_POST['name'];
    $address = $_POST['address'];
    $phone = $_POST['phone'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Insert into students table
    $sql1 = "INSERT INTO students (roll, name, address, phone, username, password)
             VALUES ('$roll', '$name', '$address', '$phone', '$username', '$password')";
    mysqli_query($conn, $sql1);

    // Insert into marks table with default zeros
    $sql2 = "INSERT INTO marks (roll, english, science, maths, total)
             VALUES ('$roll', 0, 0, 0, 0)";
    mysqli_query($conn, $sql2);

    echo "<script>alert('Student Registered Successfully');</script>";
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Register Student</title>
</head>
<body>

<h2>Register Student</h2>

<form method="post">

    <!-- ROLL NUMBER DROPDOWN -->
    <label>Roll No:</label><br>
    <select name="roll" required>
        <option value="">Select Roll No</option>
        <?php
            for($i=1; $i<=50; $i++){
                if(!in_array($i, $used)){
                    echo "<option value='$i'>$i</option>";
                }
            }
        ?>
    </select><br><br>


    <!-- NAME -->
    <label>Name:</label><br>
    <input type="text" name="name" required><br><br>

    <!-- ADDRESS -->
    <label>Address:</label><br>
    <textarea name="address" required></textarea><br><br>

    <!-- PHONE -->
    <label>Phone:</label><br>
    <input type="text" name="phone" required><br><br>

    <!-- USERNAME -->
    <label>Username:</label><br>
    <input type="text" name="username" required><br><br>

    <!-- PASSWORD -->
    <label>Password:</label><br>
    <input type="password" name="password" required><br><br>

    <!-- REGISTER BUTTON -->
    <button type="submit" name="register">Register</button>

</form>

</body>
</html>
