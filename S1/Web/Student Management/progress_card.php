<?php
include "connection.php";

// Fetch roll numbers
$rolls = mysqli_query($conn, "SELECT roll FROM students");

// Variables
$found = false;
$data = [];
$name = "";
$roll = "";

if(isset($_POST['search'])){
    $roll = $_POST['roll'];

    // Get student + marks
    $sql = "SELECT students.name, students.roll,
                   marks.english, marks.science, marks.maths, marks.total
            FROM students
            INNER JOIN marks ON students.roll = marks.roll
            WHERE students.roll='$roll'";

    $res = mysqli_query($conn, $sql);
    $data = mysqli_fetch_assoc($res);

    if($data){
        $found = true;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Progress Card</title>
</head>
<body>

<h2>Progress Card</h2>

<!-- SEARCH PART -->
<form method="post">

    <label>Select Roll No:</label>
    <select name="roll" required>
        <option value="">Select</option>

        <?php
        while($r = mysqli_fetch_assoc($rolls)){
            echo "<option value='".$r['roll']."'>".$r['roll']."</option>";
        }
        ?>
    </select>

    <button type="submit" name="search">Search</button>

</form>

<br>

<!-- SHOW PROGRESS CARD -->
<?php if($found){ ?>

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

<?php } ?>

</body>
</html>
