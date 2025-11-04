<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Form</title>
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
        <form action="studentHome.php" method="post">
            <h2>Login</h2>
            <input type="text" name="roll" placeholder="Enter your Roll No." class="textInput" required>
            <input type="password" name="password" placeholder="Enter your password" class="textInput" required>
            <input type="submit" value="Login" class="buttonInput">
        </form>
    </div>
</body>
</html>
