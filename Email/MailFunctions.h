void EmailSender_Configure(char SendMail[], char server[], char username[], char Password[], char port[], char sentFrom[])
{
	    strcat(SendMail ,sentFrom);
		strcat(SendMail, "\" /name \"");
		strcat(SendMail, username);
		strcat(SendMail, "\" /pass \"");
		strcat(SendMail ,Password);
		strcat(SendMail, "\" /server \"");
		strcat(SendMail ,server);
		strcat(SendMail ,"\" /p \"");
		strcat(SendMail , port);
		strcat(SendMail , "\" /SSL ");
		strcat(SendMail ," /rt \"");    
		strcat(SendMail ,sentFrom);
		strcat(SendMail ,"\" ");
	
}

void EmailSender_SendMail(char SendMail[], char to[], char subject[], char text[], char attachmentFile[])
{
	strcat(SendMail ,"/to \"");  
	strcat(SendMail ,to);
	strcat(SendMail ,"\" ");     
	strcat(SendMail ,"/sub \""); 
	strcat(SendMail ,subject); 
	strcat(SendMail ,"\" /b \"");
	strcat(SendMail ,text);
	strcat(SendMail ,"\" ");  
}
