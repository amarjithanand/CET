<?php
include "connection.php";

// ---- GET ROLL NUMBER FROM URL ----
if(isset($_GET['roll'])){
    $roll = $_GET['roll'];

    // Fetch student details
    $sql1 = "SELECT * FROM students WHERE roll='$roll'";
    $res1 = mysqli_query($conn, $sql1);
    $stu = mysqli_fetch_assoc($res1);

    // Fetch marks
    $sql2 = "SELECT * FROM marks WHERE roll='$roll'";
    $res2 = mysqli_query($conn, $sql2);
    $mark = mysqli_fetch_assoc($res2);
}

// ---- UPDATE STUDENT DETAILS ----
if(isset($_POST['update'])){
    $roll = $_POST['roll'];
    $name = $_POST['name'];
    $address = $_POST['address'];
    $phone = $_POST['phone'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    $english = $_POST['english'];
    $science = $_POST['science'];
    $maths = $_POST['maths'];
    $total = $english + $science + $maths;

    // Update student table
    $u1 = "UPDATE students SET 
            name='$name', 
            address='$address', 
            phone='$phone', 
            username='$username',
            password='$password'
           WHERE roll='$roll'";
    mysqli_query($conn, $u1);

    // Update marks table
    $u2 = "UPDATE marks SET 
            english='$english', 
            science='$science', 
            maths='$maths', 
            total='$total'
           WHERE roll='$roll'";
    mysqli_query($conn, $u2);

    echo "<script>alert('Student Updated Successfully');</script>";
}

// ---- DELETE STUDENT ----
if(isset($_POST['delete'])){
    $roll = $_POST['roll'];

    // Delete from marks table
    mysqli_query($conn, "DELETE FROM marks WHERE roll='$roll'");

    // Delete from students table
    mysqli_query($conn, "DELETE FROM students WHERE roll='$roll'");

    echo "<script>alert('Student Deleted Successfully');</script>";
    echo "<script>window.location='view_students.php';</script>";
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Update / Delete Student</title>

    <script>
        function calcTotal(){
            var e = parseInt(document.getElementById("eng").value) || 0;
            var s = parseInt(document.getElementById("sci").value) || 0;
            var m = parseInt(document.getElementById("mat").value) || 0;

            document.getElementById("tot").value = e + s + m;
        }
    </script>

</head>
<body>

<h2>Update / Delete Student</h2>

<form method="post">

    <input type="hidden" name="roll" value="<?php echo $roll; ?>">

    <label>Name:</label><br>
    <input type="text" name="name" value="<?php echo $stu['name']; ?>" required><br><br>

    <label>Address:</label><br>
    <textarea name="address" required><?php echo $stu['address']; ?></textarea><br><br>

    <label>Phone:</label><br>
    <input type="text" name="phone" value="<?php echo $stu['phone']; ?>" required><br><br>

    <label>Username:</label><br>
    <input type="text" name="username" value="<?php echo $stu['username']; ?>" required><br><br>

    <label>Password:</label><br>
    <input type="text" name="password" value="<?php echo $stu['password']; ?>" required><br><br>

    <hr>

    <h3>Marks</h3>

    <label>English:</label><br>
    <input type="number" id="eng" name="english" value="<?php echo $mark['english']; ?>" onkeyup="calcTotal()" required><br><br>

    <label>Science:</label><br>
    <input type="number" id="sci" name="science" value="<?php echo $mark['science']; ?>" onkeyup="calcTotal()" required><br><br>

    <label>Maths:</label><br>
    <input type="number" id="mat" name="maths" value="<?php echo $mark['maths']; ?>" onkeyup="calcTotal()" required><br><br>

    <label>Total:</label><br>
    <input type="number" id="tot" name="total" value="<?php echo $mark['total']; ?>" readonly><br><br>

    <button type="submit" name="update">Update</button>
    <button type="submit" name="delete" onclick="return confirm('Are you sure?')">Delete</button>

</form>

</body>
</html>
