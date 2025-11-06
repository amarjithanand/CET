<?php
$name = $_POST['name'];
$rollNo = $_POST['roll'];
$gender = $_POST['gender'];
$mark1 = $_POST['mark1'];
$mark2 = $_POST['mark2'];
$mark3 = $_POST['mark3'];
$totalMark = $_POST['totalMark'];



$servername = "localhost";
$username = "root";
$password = "";
$dbname = "students";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: ");
}
// echo "Connected successfully<br>";

$sql = "SELECT * FROM students";

$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        if ($row['roll'] == $rollNo) {
            echo "alert('Roll number already exists')";
        }
    }
}
    $sql_query = "INSERT INTO students(roll,Name,Gender,Mark1,Mark2,Mark3,Total) VALUES ('$rollNo', '$name','$gender','$mark1','$mark2','$mark3','$totalMark')";
    
    if (mysqli_query($conn, $sql_query)) {
        // echo "Record inserted successfully<br>";
    } else {
        echo "Error: " . mysqli_error($conn) . "<br>";
    }



?>
<table border="2" cellspacing="1" cellpadding="10px">
    <tr>
        <th>
            <h3>Roll No</h3>
        </th>
        <th>
            <h3>Name</h3>
        </th>
        <th>
            <h3>Gender</h3>
        </th>
        <th>
            <h3>Mark 1</h3>
        </th>
        <th>
            <h3>Mark 2</h3>
        </th>
        <th>
            <h3>Mark 3</h3>
        </th>
        <th>
            <h3>Total Mark</h3>
        </th>
    </tr>
    <?php
    $sql = "SELECT * FROM students";

    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['roll'] . "</td>";
            echo "<td>" . $row['Name'] . "</td>";
            echo "<td>" . $row['Gender'] . "</td>";
            echo "<td>" . $row['Mark1'] . "</td>";
            echo "<td>" . $row['Mark2'] . "</td>";
            echo "<td>" . $row['Mark3'] . "</td>";
            echo "<td>" . $row['Total'] . "</td>";
            echo "</tr>";
        }
    } else {
        echo "<tr><td colspan='4'>No records found</td></tr>";
    }

    mysqli_close($conn);
    ?>
</table>