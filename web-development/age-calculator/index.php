<!DOCTYPE html>
<html style="overflow: hidden;">
    <head>
        <title>Birthday</title>
    </head>
    <body style="font-family: Arial, Helvetica, sans-serif;">
        <?php
        function calcBday($birthDate) {
            $currentDate = new DateTime("now");
            $GLOBALS["age"] = $currentDate->diff($birthDate)->y;
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST" and isset($_POST["birthdate"])) {
            calcBday(DateTime::createFromFormat("U", strtotime($_POST["birthdate"])));
        }
        ?>
        <div style="display: flex; height: 100vh; flex-direction: column; align-items: center; justify-content: center; ">
            <form method="post" action="">
                <label for="birthdate">Date of birth</label>
                <input type="date" id="birthdate" name="birthdate" onchange="this.form.submit()" value="<?php echo isset($_POST["birthdate"]) ? date("Y-m-d", strtotime($_POST['birthdate'])) : "" ?>">
            </form>
            <div style="margin-top: 20px; font-size: xx-large;">
                <?php echo isset($GLOBALS["age"]) ? $GLOBALS["age"] : "0"; ?> year(s) old
            </div>
        </div>
    </body>
</html>