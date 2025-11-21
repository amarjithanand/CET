<?php
include "connection.php";

// FETCH TOP 5 STUDENTS BASED ON TOTAL
$sql = "SELECT students.roll, students.name,
               marks.english, marks.science, marks.maths, marks.total
        FROM students
        INNER JOIN marks ON students.roll = marks.roll
        ORDER BY marks.total DESC
        LIMIT 5";

$result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Top 5 Students</title>
</head>
<body>

<h2>Top 5 Students Based on Total Marks</h2>

<table border="1" cellpadding="8">
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>English</th>
        <th>Science</th>
        <th>Maths</th>
        <th>Total</th>
    </tr>

    <?php 
    while($row = mysqli_fetch_assoc($result)){
        echo "<tr>";
        echo "<td>".$row['roll']."</td>";
        echo "<td>".$row['name']."</td>";
        echo "<td>".$row['english']."</td>";
        echo "<td>".$row['science']."</td>";
        echo "<td>".$row['maths']."</td>";
        echo "<td>".$row['total']."</td>";
        echo "</tr>";
    }
    ?>
</table>

</body>
</html>
