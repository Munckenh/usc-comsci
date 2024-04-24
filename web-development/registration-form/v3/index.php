<!DOCTYPE html>
<html>

<head>
    <title>Registration form</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="./style.css">
</head>

<body>
    <?php
    $host = "localhost";
    $user = "user";
    $password = "password";
    $db = "registration_db";

    $conn = new mysqli($host, $user, $password, $db);
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST" and isset($_POST["submit"])) {
        $fullName = htmlspecialchars($_POST["fullName"]);
        $course = htmlspecialchars($_POST["course"]);
        $emailAddress = htmlspecialchars($_POST["emailAddress"]);
        $previousSchool = htmlspecialchars($_POST["previousSchool"]);
        $applicationReason = htmlspecialchars($_POST["applicationReason"]);

        $sql = "INSERT INTO `user` (`full_name`, `email_address`, `course`, `previous_school`, `reason`) VALUES ('$fullName', '$emailAddress', '$course', '$previousSchool', '$applicationReason');";
        mysqli_query($conn, $sql);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST" and isset($_POST["clear"])) {
        $fullName = "";
        $course = "";
        $emailAddress = "";
        $previousSchool = "";
        $applicationReason = "";
    }
    ?>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.min.js"></script>
    <div class="container">
        <div class="row">
            <div class="col-sm">
                <div class="border m-3">
                    <div class="px-3 py-2 form-head">Registration Form</div>
                    <form class="px-3 py-4" method="post">
                        <div class="mb-3">
                            <label for="fullName" class="form-label">Full name</label>
                            <input required type="text" id="fullName" name="fullName" class="form-control">
                        </div>
                        <div class="mb-3">
                            <label for="course" class="form-label">Course</label>
                            <select required id="course" name="course" class="form-select">
                                <option value="" disabled selected hidden>Select a course</option>
                                <option value="BS Computer Science">BS Computer Science</option>
                                <option value="BS Information Technology">BS Information Technology</option>
                                <option value="BS Information Systems">BS Information Systems</option>
                            </select>
                        </div>
                        <div class="mb-3">
                            <label for="emailAddress" class="form-label">Email address</label>
                            <input required type="email" id="emailAddress" name="emailAddress" class="form-control">
                        </div>
                        <div class="mb-3">
                            <label for="previousSchool" class="form-label">Previous school</label>
                            <input required type="text" id="previousSchool" name="previousSchool" class="form-control">
                        </div>
                        <div class="mb-3">
                            <label for="applicationReason" class="form-label">Why did you choose USC?</label>
                            <textarea class="form-control" id="applicationReason" name="applicationReason"></textarea>
                        </div>
                        <button type="submit" class="btn btn-primary" name="submit">Submit</button>
                    </form>
                </div>
            </div>
            <div class="col-sm">
                <div class="border m-3">
                    <div class="px-3 py-2 form-head">User details</div>
                    <div class="px-3 py-4">
                        <div class="mb-3">
                            <b>Full name: </b><?php echo isset($_POST["fullName"]) ? htmlspecialchars($_POST["fullName"]) : ""; ?></br>
                            <b>Course: </b><?php echo isset($_POST["course"]) ? htmlspecialchars($_POST["course"]) : ""; ?></br>
                            <b>Email: </b><?php echo isset($_POST["emailAddress"]) ? htmlspecialchars($_POST["emailAddress"]) : ""; ?></br>
                            <b>Previous school: </b><?php echo isset($_POST["previousSchool"]) ? htmlspecialchars($_POST["previousSchool"]) : ""; ?></br>
                            <b>Reason: </b><?php echo isset($_POST["applicationReason"]) ? htmlspecialchars($_POST["applicationReason"]) : ""; ?>
                        </div>
                        <form method="post">
                            <button type="submit" class="btn btn-primary" name="clear">Clear</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
    </div>
</body>

</html>