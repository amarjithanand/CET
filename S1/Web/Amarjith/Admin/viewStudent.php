<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>View Student Detail</title>
</head>
<body>
    <h1>Student Details</h1>
    <?php
    $servername = "localhost";
    $username = 'root';
    $password = "";
    $dbname = "students";

    $name = $_POST['searchbar'];
    $conn = mysqli_connect($servername,$username,$password, $dbname);

    $sql_query = "SELECT * FROM student";
    
    $result = mysqli_query($conn,$sql_query);
    if(mysqli_num_rows($result)>0){
        while($row = mysqli_fetch_assoc($result)){
            if($row['Name']==$name){
                $roll_no = $row['Roll'];
                break;
            }
            else{
                $roll_no=0;
            }
        }
    }
$page = "
    <table border = '2px' cellspacing = '1px' cellpadding = '10x'>
    <tr><th colspan='2'>PROGRESS REPORT</th></tr>
    <tr><td>AGE </td><td>".$row["Roll"]."</td></tr>
    <tr><td>NAME </td><td>".$row["Name"]."</td></tr>
    <tr><td>AGE </td><td>".$row["Address"]."</td></tr>
    </table>";

    if($roll_no!=0){
        echo $page;
    }
    else{
        echo "<H1 style ='color:red;'>No Such Student</H1>";
    }
    ?>

</body>
</html>