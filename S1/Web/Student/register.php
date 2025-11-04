<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Form</title>
    <style>

        body {
            font-family: "Poppins", sans-serif;
            background: #fff;
            height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            margin: 0;
        }
        .container {
            background-color: #fff;
            width: 100%;
            max-width: 400px;
            padding: 40px;
            border-radius: 20px;
            box-shadow: 0px 10px 25px rgba(0, 0, 0, 0.15);
            transition: all 0.3s ease;
        }

        .container:hover {
            transform: translateY(-5px);
        }

        h2 {
            text-align: center;
            color: #333;
            margin-bottom: 30px;
        }


        .textInput {
            width: 100%;
            padding: 12px 15px;
            margin-bottom: 20px;
            border: 1px solid #ccc;
            border-radius: 10px;
            font-size: 16px;
            transition: border 0.3s ease;
        }

        .textInput:focus {
            border-color: #f6a623;
            outline: none;
            box-shadow: 0 0 5px rgba(246, 166, 35, 0.5);
        }
.textInput>select {
            width: 100%;
            padding: 12px 15px;
            margin-bottom: 20px;
            border: 1px solid #ccc;
            border-radius: 10px;
            font-size: 16px;
            transition: all 0.3s ease;
            background-color: #fff;
            appearance: none; 
            -webkit-appearance: none;
            -moz-appearance: none;
            background-image: url('data:image/svg+xml;utf8,<svg fill="%23f6a623" height="24" viewBox="0 0 24 24" width="24" xmlns="http://www.w3.org/2000/svg"><path d="M7 10l5 5 5-5z"/></svg>');
            background-repeat: no-repeat;
            background-position: right 10px center;
            background-size: 18px;
        }

        select:focus,
        .textInput:focus {
            border-color: #f6a623;
            outline: none;
            box-shadow: 0 0 5px rgba(246, 166, 35, 0.5);
        }


        .buttonInput {
            width: 100%;
            background-color: #f6a623;
            color: white;
            padding: 12px;
            font-size: 16px;
            border: none;
            border-radius: 10px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

        .buttonInput:hover {
            background-color: #f08c00;
        }
    </style>
</head>
<body>
    <div class="container">
        <form action="submit.php" method="post">
            <h2>Student Register</h2>
            <input type="text" name="name" placeholder="Enter name" class="textInput" required>
            <?php
             $servername = "localhost";
            $username = "root";
            $password = "";
            $dbname = "students";

            $conn = mysqli_connect($servername, $username, $password, $dbname);
            $sql = "SELECT roll FROM student";
            $result = mysqli_query($conn, $sql);

            $existing_rolls = [];
            if ($result && mysqli_num_rows($result) > 0) {
                while ($row = mysqli_fetch_assoc($result)) {
                    $existing_rolls[] = $row['roll'];
                }
            }

            echo "<select name='roll' class ='textInput'>";
            for ($x = 1; $x <= 50; $x++) {
                if (!in_array($x, $existing_rolls)) {
                    echo "<option value='$x'>$x</option>";
                }
            }
            echo "</select>";
            ?>
            <textarea name="address" id="address" rows="4" class="textInput" placeholder="Enter Adress" style="resize: none;"></textarea>
            <input type="password" name="password" placeholder="Enter password" class="textInput" required>
            <input type="submit" value="Login" class="buttonInput">
        </form>
    </div>
</body>
</html>