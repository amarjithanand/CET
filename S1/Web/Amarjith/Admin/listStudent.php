<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Student Records</title>
<style>
    body {
        font-family: "Poppins", sans-serif;
        background: #fff;
        height: 100vh;
        margin: 0;
        display: flex;
        justify-content: center;
        align-items: center;
    }

    .table-container {
        background: #fff;
        padding: 40px;
        border-radius: 20px;
        box-shadow: 0px 10px 25px rgba(0, 0, 0, 0.15);
        width: 90%;
        max-width: 800px;
        transition: all 0.3s ease;
    }

    .table-container:hover {
        transform: translateY(-5px);
    }

    h2 {
        text-align: center;
        margin-bottom: 25px;
        color: #333;
    }

    table {
        border-collapse: collapse;
        width: 100%;
        font-size: 16px;
    }

    th, td {
        text-align: left;
        padding: 12px 15px;
    }

    th {
        background-color: #f6a623;
        color: #fff;
        text-transform: uppercase;
        letter-spacing: 0.5px;
    }

    tr:nth-child(even) {
        background-color: #f9f9f9;
    }

    tr:hover {
        background-color: #fff6e0;
        transition: 0.3s ease;
    }

    td {
        border-bottom: 1px solid #ddd;
    }

    .no-records {
        text-align: center;
        color: #999;
        padding: 20px;
    }

    /* Button to go back or refresh */
    .buttonInput {
        width: 200px;
        background-color: wheat;
        color: black;
        padding: 12px;
        font-size: 16px;
        border: none;
        border-radius: 10px;
        cursor: pointer;
        transition: background-color 0.3s ease;
        display: block;
        margin: 25px auto 0 auto;
        text-align: center;
        text-decoration: none;
    }

    .buttonInput:hover {
        background-color: #f08c00;
    }
</style>
</head>
<body>
    <div class="table-container">
        <h2>📋 Student Records</h2>
        <form action="viewStudent.php" method = "post">
        <input type="search" name="searchbar" id="">
        <input type="submit" value="search">
        </form>
        <table>
            <tr>
                <th>Roll No</th>
                <th>Name</th>
                <th>Address</th>
                <th>Password</th>
            </tr>

            <?php
            $servername = "localhost";
            $username = "root";
            $password = "";
            $dbname = "students";

            $conn = mysqli_connect($servername, $username, $password, $dbname);

            if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
            }

            $sql = "SELECT * FROM student";
            $result = mysqli_query($conn, $sql);
            
            if (mysqli_num_rows($result) > 0) {
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<tr>";
                    echo "<td>" . $row['Roll'] . "</td>";
                    echo "<td>" . htmlspecialchars($row['Name']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['Address']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['Password']) . "</td>";
                    echo "</tr>";
                }
            } else {
                echo "<tr><td colspan='4' class='no-records'>No records found</td></tr>";
            }

            mysqli_close($conn);
            ?>
        </table>

        <a href="register.php" class="buttonInput">➕ Register New Student</a>
    </div>
</body>
</html>
