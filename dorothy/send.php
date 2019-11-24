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
$mail->Username = 'g10206023@gmail.com'; // SMTP username
$mail->Password = 'ji3g4284gj94ek'; // SMTP password
$mail->SMTPSecure = 'tls'; // Enable TLS encryption, `ssl` also accepted
$mail->Port = 587; // TCP port to connect to

$mail->setFrom('g10206023@gmail.com', '帥ND'); //寄件的Gmail
$mail->addAddress('chuckchen7994@gmail.com', '家人'); // 收件的信箱

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
