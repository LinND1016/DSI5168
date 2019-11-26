<?php
//UTF 8 setting
mb_internal_encoding('UTF-8');
//設定time out
set_time_limit(120);
//echo !extension_loaded('openssl')?"Not Available":"Available";
require_once("./PHPMailer-5.2.9/PHPMailerAutoload.php"); //記得引入檔案 
$mail = new PHPMailer;

//$mail->SMTPDebug = 3; // 開啟偵錯模式

$mail->isSMTP(); // Set mailer to use SMTP
$mail->Host = 'smtp.gmail.com'; // Specify main and backup SMTP servers
$mail->SMTPAuth = true; // Enable SMTP authentication
$mail->Username = '帳號'; // SMTP username
$mail->Password = '密碼'; // SMTP password
$mail->SMTPSecure = 'tls'; // Enable TLS encryption, `ssl` also accepted
$mail->Port = 587; // TCP port to connect to

$mail->setFrom('你的mail@gmail.com', '你的名字'); //寄件的Gmail
$mail->addAddress('對方的mail@gmail.com', '對方的名字'); // 收件的信箱

// $mail->AddCC('chuck@corma.com.tw');

$mail->isHTML(true); // Set email format to HTML

/*
    內文
*/

$mail->Subject = '求救！! help !!';
$mail->Body = "help!!help!!";
$mail->AltBody = "help!!help!!";

if ($mail->send()) {
	echo 'ok';
}
else{
	echo "wrong";
}

?> 
