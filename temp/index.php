<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

    <form action="/Amarjith/submit.php"  name ="markEntryForm" onsubmit="calculate()" method="post">
            <table border="2" cellspacing="1" cellpadding="10px">
                <tr>
                    <th colspan="2"><h3>REGISTRATION FORM</h3></th>
                </tr>
                    <td>Roll No.:</td>
                    <td>
                        <?php
            $servername = "localhost";
            $username = "root";
            $password = "";
            $dbname = "students";

            $conn = mysqli_connect($servername, $username, $password, $dbname);

            if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
            }

            $sql = "SELECT roll FROM students";
            $result = mysqli_query($conn, $sql);

            $existing_rolls = [];
            if ($result && mysqli_num_rows($result) > 0) {
                while ($row = mysqli_fetch_assoc($result)) {
                    $existing_rolls[] = $row['roll'];
                }
            }

            echo "<select name='roll'>";
            for ($x = 1; $x <= 50; $x++) {
                if (!in_array($x, $existing_rolls)) {
                    echo "<option value='$x'>$x</option>";
                }
            }
            echo "</select>";

            mysqli_close($conn);
            ?>
                    </td>
                </tr>
                <tr>
                    <td>Name :</td>
                    <td><input type="text" name="name"></td>
                </tr>
                <tr>
                    <td>GENDER :</td>
                    <td><select name="gender">
                        <option value="male">Male</option>
                        <option value="female">Female</option>
                        <option value="others">Others</option>
                    </select></td>
                </tr>
                <tr>
                    <td>MARK 1:</td>
                    <td><input type="text" name="mark1"></td>
                </tr>
                <tr>
                    <td>MARK 2:</td>
                    <td><input type="text" name="mark2"></td>
                </tr>
                <tr>
                    <td>MARK 3:</td>
                    <td><input type="text" name="mark3"></td>
                </tr>
                <tr>
                    <td>TOTAL MARK:</td>
                    <td><input type="text" name="totalMark" readonly></button></td>
                </tr>
                <th><input type="reset" value="RESET" style="border-radius: 20px;"></th>
                <th><input type="submit" value="SUBMIT" style="border-radius: 20px;"></th>
            </table>
        </form>
        <script>
            function calculate(){
                let m1 = document.forms['markEntryForm']['mark1'].value;
                let m2 = document.forms['markEntryForm']['mark2'].value;
                let m3 = document.forms['markEntryForm']['mark3'].value;
                let total = Number(m1)+Number(m2)+Number(m3);
                document.forms['markEntryForm']['totalMark'].value = total;
            }
        </script>
</body>
</html>