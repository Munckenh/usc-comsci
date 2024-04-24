<!DOCTYPE html>
<html style="overflow: hidden;">

<head>
    <title>Birthday</title>
</head>

<body style="font-family: Arial, Helvetica, sans-serif;">
    <?php
    function getAge()
    {
        $currentDate = new DateTime("now");
        return $currentDate->diff(DateTime::createFromFormat("U", strtotime($_POST["birthdate"])))->y;
    }

    function insertInfo()
    {
        $firstName = htmlspecialchars(trim($_POST["firstname"]));
        $lastName = htmlspecialchars(trim($_POST["lastname"]));
        $middleName = htmlspecialchars(trim($_POST["middlename"]));
        $birthDate = htmlspecialchars($_POST["birthdate"]);
        $age = getAge();

        $servername = "localhost";
        $username = "user";
        $password = "password";
        $db = "person_db";

        $conn = new mysqli($servername, $username, $password, $db);
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $sql = "INSERT INTO `person` (`first_name`, `middle_name`, `last_name`, `birthdate`, `age`) VALUES ('$firstName', '$middleName', '$lastName', '$birthDate', '$age');";
        mysqli_query($conn, $sql);
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST" and isset($_POST["submit"])) {
        insertInfo();
    }
    ?>
    <div style="display: flex; height: 100vh; flex-direction: column; align-items: center; justify-content: center;">
        <form style="border: 1px solid; border-radius: 5px; padding: 1rem;" method="post" action="">
            <div style="margin-bottom: 1rem;">
                <label for="firstname" style="margin-bottom: 0.5rem;">First name</label></br>
                <input required type="text" id="firstname" name="firstname">
            </div>
            <div style="margin-bottom: 1rem;">
                <label for="lastname" style="margin-bottom: 0.5rem;">Last name</label></br>
                <input required type="text" id="lastname" name="lastname">
            </div>
            <div style="margin-bottom: 1rem;">
                <label for="middlename" style="margin-bottom: 0.5rem;">Middle name</label></br>
                <input type="text" id="middlename" name="middlename">
            </div>
            <div style="margin-bottom: 1rem;">
                <label for="birthdate" style="margin-bottom: 0.5rem;">Date of birth</label></br>
                <input type="date" id="birthdate" name="birthdate">
            </div>
            <button type="submit" class="btn btn-primary" name="submit" onclick="this.form.submit()">Submit</button>
        </form>
    </div>
</body>

</html>