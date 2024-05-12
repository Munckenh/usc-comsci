<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]>      <html class="no-js"> <!--<![endif]-->
<html>

<head>
    <title>My First DB Connection</title>
    <style>
        body {
            background-color: #f6f4f0;
        }

        p {
            margin: 0;
        }

        table,
        th,
        td {
            border: 1px solid black;
            border-collapse: collapse;
            padding: 5px 10px;
        }

        .view {
            border: #000000 1.5px solid;
            border-radius: 5px;
            width: 20rem;
            padding: 0.75rem;
            margin-bottom: 1rem;
        }

        .container {
            border: #000000 1.5px solid;
            border-radius: 5px;
            width: 20rem;
            padding: 0.75rem;
        }

        .form {
            display: flex;
            flex-wrap: wrap;
            gap: 0.5rem;
        }

        .input {
            flex: 1 0 10rem;
            border: #000000 1.5px solid;
            border-radius: 2.5px;
            padding: 5px 10px;
        }

        .button {
            flex: 1 0 5rem;
            background-color: #c0b9a5;
            border: #000000 1.5px solid;
            border-radius: 2.5px;
            padding: 7.5px;
        }
    </style>
    <?php
    include('db.php');
    include('process.php');
    ?>
</head>

<body>
    <div class="container">
        <form method="POST" action="process.php" class="form">
            <input type="text" name="myname" placeholder="Name" class="input">
            <input type="text" name="mycourse" placeholder="Course" class="input">
            <button type="submit" class="submit">Submit</button>
        </form>
    </div>
    </br>
    <?php
    getData($conn);
    ?>
</body>

</html>