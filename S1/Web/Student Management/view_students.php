<?php
include "connection.php";

// JOIN students + marks tables
$sql = "SELECT students.roll, students.name, students.address, students.phone,
               students.username, marks.english, marks.science, marks.maths, marks.total
        FROM students
        INNER JOIN marks ON students.roll = marks.roll
        ORDER BY students.roll";

$result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>View Students</title>
</head>
<body>

<h2>Student Details</h2>

<table border="1" cellpadding="8">
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Username</th>
        <th>English</th>
        <th>Science</th>
        <th>Maths</th>
        <th>Total</th>
        <th>Edit</th>
    </tr>

    <?php
    while($row = mysqli_fetch_assoc($result)){
        echo "<tr>";
        echo "<td>".$row['roll']."</td>";
        echo "<td>".$row['name']."</td>";
        echo "<td>".$row['address']."</td>";
        echo "<td>".$row['phone']."</td>";
        echo "<td>".$row['username']."</td>";
        echo "<td>".$row['english']."</td>";
        echo "<td>".$row['science']."</td>";
        echo "<td>".$row['maths']."</td>";
        echo "<td>".$row['total']."</td>";

        // Edit button
        echo "<td><a href='update_delete_students.php?roll=".$row['roll']."'>Edit</a></td>";

        echo "</tr>";
    }
    ?>

</table>

</body>
</html>
