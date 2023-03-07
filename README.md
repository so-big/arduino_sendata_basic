basic post data form arduino to server for education
1.use this 01 script on esp8266
2.use this 02 script on php serverside

working datawill send to php server in line 34 "test=datayouwant"
php script will read test variable with function $_POST["test"]; and return this with echo function to client.
we can do something to this data like store to database or write to server text file.
but now it only echo back to client side.

we can use this function to read database too like this

sned  $_POST["functionname"]; to server side or create new script.php on difference uri
call it and use php server side to read data on server can lern it https://www.w3schools.com/php/php_mysql_select.asp
