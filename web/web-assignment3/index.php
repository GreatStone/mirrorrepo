<html>
<head>
  <meta charset="utf-8">
  <title>GreatStone's Page</title>
  <link href="home.css" type="text/css" rel="stylesheet"/>
</head>
<body>
  <div class="title">
    <p>
      GreatStone's Page
    </p>
  </div>
  <div align="center">
    <?php
    if (!$_COOKIE["gshome_name"]){ ?>
    <form action="login.php" method="post">
      <div class="info">
        <p class="label"> username </p>
        <input  type="text" name="username"/>
      </div>
      <div class="info">
        <p class="label"> password </p>
        <input type="password" name="password"/>
      </div>
    </div>
    <div align="center">
      <input class="button" type="submit" value="login" width="60px">
    </form>
  </div>
  <div class="line">
  </div>
  <div align="center">
    <a class="turn" href="register.php">register</a>
  </div>
  <?php }
  else{
    ?>
    <div class = "title"> 
      <p> Welcome, <? echo $_COOKIE["gshome_name"]?> </p>
      <p> You have login this website for  <? echo $_COOKIE["viscount"] ?> times </p>
    </div>
    <div>
      <a class="turn" href="logout.php"> logout </a>
    </div>
    <?php } ?>
    <div class="feet">
      <p>
        by GreatStone 2014.04.09 12281054@bjtu.edu.cn
      </p>
    </div>
  </body>
  </html>
