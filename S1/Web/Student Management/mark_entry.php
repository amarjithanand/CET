<?php
include "connection.php";

// -------- FETCH ALL ROLL NUMBERS --------
$rolls = mysqli_query($conn, "SELECT roll FROM students");

// -------- GET STUDENT NAME WHEN SEARCHED --------
$name = "";
if(isset($_POST['search'])){
    $roll = $_POST['roll'];
    $q = "SELECT name FROM students WHERE roll='$roll'";
    $r = mysqli_query($conn, $q);
    $row = mysqli_fetch_assoc($r);
    if($row){
        $name = $row['name'];
    }
}

// -------- UPDATE MARKS IN TABLE --------
if(isset($_POST['submit_marks'])){
    $roll = $_POST['roll'];
    $english = $_POST['english'];
    $science = $_POST['science'];
    $maths = $_POST['maths'];
    $total = $_POST['total'];

    $u = "UPDATE marks SET english='$english', science='$science', maths='$maths', total='$total'
          WHERE roll='$roll'";

    mysqli_query($conn, $u);

    echo "<script>alert('Marks Updated Successfully');</script>";
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Mark Entry</title>

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

<h2>Mark Entry</h2>

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

<!-- DISPLAY STUDENT NAME -->
<?php if($name != ""){ ?>
    <b>Student Name: <?php echo $name; ?></b><br><br>
<?php } ?>

<!-- MARK ENTRY FORM -->
<form method="post">

    <!-- Hidden roll value passed again -->
    <input type="hidden" name="roll" value="<?php if(isset($roll)) echo $roll; ?>">

    <label>English:</label><br>
    <input type="number" id="eng" name="english" onkeyup="calcTotal()" required><br><br>

    <label>Science:</label><br>
    <input type="number" id="sci" name="science" onkeyup="calcTotal()" required><br><br>

    <label>Maths:</label><br>
    <input type="number" id="mat" name="maths" onkeyup="calcTotal()" required><br><br>

    <label>Total:</label><br>
    <input type="number" id="tot" name="total" readonly><br><br>

    <button type="submit" name="submit_marks">Submit</button>

</form>

</body>
</html>
