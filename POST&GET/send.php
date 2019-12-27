<?php
//UTF 8 setting
$value = $_GET['value'];
$total = $_GET['total'];
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
$mail->Username = ''; // SMTP username
$mail->Password = ''; // SMTP password
$mail->SMTPSecure = 'tls'; // Enable TLS encryption, `ssl` also accepted
$mail->Port = 587; // TCP port to connect to

$mail->setFrom('', 'POST&GET--DSI5168'); //寄件的Gmail
$mail->addAddress('', '家人'); // 收件的信箱

// $mail->AddCC('chuck@corma.com.tw');

$mail->isHTML(true); // Set email format to HTML

/*
    內文
*/

$mail->Subject = 'Count value';
$mail->Body = "Count total" . $total;
$mail->AltBody = "Count total" . $total;

if ($mail->send()) {
	echo 'ok';
}
else{
	echo "wrong";
}

$curl = curl_init();

curl_setopt_array($curl, array(
  CURLOPT_URL => "https://ideaschain.com.tw/iot/v1/rawdata/7590582701435470",
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => "",
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 30,
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => "POST",
  CURLOPT_POSTFIELDS => "[{\"sid\":\"1234\",\"value\":[\"$value\"]}]\r\n",
  CURLOPT_HTTPHEADER => array(
    "AK: mj3TDDUzY8Oru2H5",
    "Accept: */*",
    "Accept-Encoding: gzip, deflate",
    "Cache-Control: no-cache",
    "Connection: keep-alive",
    "Content-Length: 32",
    "Content-Type: application/json",
    "Host: ideaschain.com.tw",
    "Postman-Token: 162133de-0bb9-4aa9-ac30-0de717abbd26,eaace739-4597-4baf-8bc0-cec4f28dd822",
    "User-Agent: PostmanRuntime/7.20.1",
    "cache-control: no-cache"
  ),
));

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);


?> 
