#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50

typedef struct {
    int seatNumber;
    char passengerName[50];
    int isBooked;
} Seat;

Seat seats[MAX_SEATS];

void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
    }
}

void bookSeat() {
    int seatNumber;
    char name[50];

    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (seats[seatNumber - 1].isBooked) {
        printf("Seat %d is already booked.\n", seatNumber);
    } else {
        printf("Enter passenger name: ");
        scanf("%s", name);
        seats[seatNumber - 1].isBooked = 1;
        strcpy(seats[seatNumber - 1].passengerName, name);
        printf("Seat %d successfully booked for %s.\n", seatNumber, name);
    }
}

void viewSeats() {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].isBooked) {
            printf("Seat %d is available.\n", seats[i].seatNumber);
        }
    }
}

void viewReservations() {
    printf("\nBooked Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].isBooked) {
            printf("Seat %d - Passenger: %s\n", seats[i].seatNumber, seats[i].passengerName);
        }
    }
}

int main() {
    int choice;
    initializeSeats();

    do {
        printf("\nFlight Reservation System\n");
        printf("1. Book a Seat\n");
        printf("2. View Available Seats\n");
        printf("3. View Reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                viewSeats();
                break;
            case 3:
                viewReservations();
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
