import java.util.*;

public class Cypher{

	public static String encrypt(String message, char password){
		String encryptedMessage = "";
		char c = 0;
		for(int i = 0; i < message.length(); i++){
			c = message.charAt(i);
			c = (char)(c + password);
			encryptedMessage = encryptedMessage + c;
		}
		return encryptedMessage;
	}
	
	public static String decrypt(String message, char password){
		String decryptedMessage = "";
		char c = 0;
		for(int i = 0; i < message.length(); i++){
			c = message.charAt(i);
			c = (char)(c - password);
			decryptedMessage = decryptedMessage + c;
		}
		return decryptedMessage;
	}

	public static String SuperEncrypt(String message, String password){
		String encryptedMessage = "";
		char c = 0;
		for(int i = 0; i < message.length(); i++){
			c = message.charAt(i);
			c = (char)(c + password.charAt(i % password.length()));
			encryptedMessage = encryptedMessage + c;
		}
		return encryptedMessage;
	}

	public static String SuperDecrypt(String message, String password){
		String decryptedMessage = "";
		char c = 0;
		for(int i = 0; i < message.length(); i++){
			c = message.charAt(i);
			c = (char)(c - password.charAt(i % password.length()));
			decryptedMessage = decryptedMessage + c;
		}
		return decryptedMessage;
	}

	public static void symetricalEncryption(){
		String message = "My name is Ayasha and I like cheesecake.";
		String encrypt = encrypt(message,'|');
		System.out.println("Encryped: "+encrypt);
		System.out.println("Decrypted: "+decrypt(encrypt,'|'));

		encrypt = SuperEncrypt(message,"Fahim");
		System.out.println("Encryped: "+encrypt);
		System.out.println("Decrypted: "+SuperDecrypt(encrypt,"Fahim"));
	}

	public static String getCypher(String input){
		String output = "";
		for(int i = 0; i < input.length(); i++){
			char in = input.charAt(i);
			char out = (char) (in * 2 + 1);
			output += out;
		}
		return output;
	}

	public static String deCypher(String cyphertext){
		String output = "";
		for(int i = 0; i < cyphertext.length(); i++){
			char in = cyphertext.charAt(i);
			char out = (char) ((in-1)/2);
			output += out;
		}
		return output;
	}

	public static void asymetricalEncryption(){
		System.out.println(getCypher("I like cookies."));
		System.out.println(deCypher(getCypher("I like cookies.")));
	}

	public static void main(String[] args){
		asymetricalEncryption();
	}
}