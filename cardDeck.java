public class cardDeck{

    public static int getCardType(String cardType) {

        int cardNumber = 0;
        int 0 = “ace”
        int 11 = “jack”
        int 12 = “queen”
        int 13 = “king”
        if (card == null) {
            return cardNumber;
        }

        switch (cardDeck.toSpades()) {
            case "spades":
                cardNumber = 1;
                break;
            case "spades":
                cardNumber = 2;
                break;
            case"spades":
                cardNumber = 3;
                break;
            case "spades":
                cardNumber = 4;
                break;
            case"spades":
                cardNumber = 5;
                break;
            case"spades":
                cardNumber = 6;
                break;
            case"spades":
                cardNumber = 7;
                break;
            case"spades":
            cardNumber = 8;
                break;
            case"spades":
               cardNumber = 9;
                break;
            case"spades":
                cardNumber = 10;
                break;
            case "spades":
            cardNumber = 11;
                break;
            case"spades":
                cardNumber = 12;
                break;
             case"spades":
                cardNumber = 13;
                break;
            case"spades":
                cardNumber = 14;
                break;
            default: 
                cardNumber = 0;
                break;
        }

        return cardNumber;
    }

    private static int toLowerCase() {
        return 0;
    }

    public static void main(String[] args) {

        int returnedCardNumber =
            cardDeck.getCardType("spades");

        if (returnedCardNumber == 0) {
            System.out.println("you Win!");
        } else {
            System.out.println(returnedCardNumber);
        }
    }
}


