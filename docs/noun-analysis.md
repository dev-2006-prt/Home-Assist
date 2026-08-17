# Noun–Verb Analysis

## 1. Purpose

Noun–verb analysis was performed on the three use-case specifications:

- UC-01: Book Service
- UC-02: View Services
- UC-03: Manage Booking

Nouns were considered as potential domain classes, while verbs were considered as possible responsibilities or operations.

---

## 2. Raw Candidate List

### Nouns from UC-01: Book Service

- Customer
- Service
- Service Provider
- Admin
- Booking
- System
- Service Details
- Time Slot
- Date
- Time
- Booking Summary
- Booking Confirmation
- Booking Details
- Booking Status
- Availability
- Service Selection Page
- Booking Request

### Nouns from UC-02: View Services

- Customer
- Service
- Service Provider
- Admin
- System
- Service Details
- Service List
- Service Availability
- Main Menu

### Nouns from UC-03: Manage Booking

- Service Provider
- Customer
- Admin
- Booking
- Service
- System
- Booking Request
- Booking Details
- Booking Status
- Issue

### Combined Raw Candidate List

1. Customer
2. Service Provider
3. Admin
4. Service
5. Booking
6. System
7. Service Details
8. Time Slot
9. Date
10. Time
11. Booking Summary
12. Booking Confirmation
13. Booking Details
14. Booking Status
15. Availability
16. Service Selection Page
17. Booking Request
18. Service List
19. Service Availability
20. Main Menu
21. Issue

---

## 3. Verb Analysis

### UC-01: Book Service

The main verbs identified are:

- log in
- view
- select
- display
- choose
- check
- confirm
- create
- store
- cancel
- inform
- return

### UC-02: View Services

The main verbs identified are:

- log in
- select
- retrieve
- display
- view
- choose
- return

### UC-03: Manage Booking

The main verbs identified are:

- log in
- open
- display
- select
- accept
- reject
- perform
- update
- store
- inform

These verbs are used later to identify responsibilities and operations of the surviving classes.

---

## 4. Four Filters Used

The following four filters are used to evaluate candidate classes:

1. Redundant
2. Irrelevant
3. Attribute
4. Implementation/UI-specific

---

## 5. Surviving Classes

After applying the filters, the following candidates survive as domain classes:

1. Customer
2. ServiceProvider
3. Admin
4. Service
5. Booking
6. TimeSlot

### Customer

Customer is a primary actor who views services, selects services, books services, and views booking information.

### ServiceProvider

ServiceProvider receives, accepts, rejects, and manages bookings and performs the requested service.

### Admin

Admin is involved in monitoring and managing bookings in the Home-Assist system.

### Service

Service represents the home service that the customer wants to request.

### Booking

Booking is the central transaction in the system. It is created, stored, confirmed, rejected, completed, and updated.

### TimeSlot

TimeSlot represents the selected date and time for a booking and is involved in checking service-provider availability.

---

## 6. Discarded Candidates and Filters

| Candidate | Result | Filter | Reason |
|---|---|---|---|
| System | Discarded | Implementation/UI-specific | The system is the software boundary and is not a domain entity. |
| Service Details | Discarded | Attribute | Service details are information belonging to the Service class. |
| Date | Discarded | Attribute | Date is information belonging to a TimeSlot. |
| Time | Discarded | Attribute | Time is information belonging to a TimeSlot. |
| Booking Summary | Discarded | Attribute | A booking summary is derived from Booking information. |
| Booking Confirmation | Discarded | Attribute | Confirmation is represented through the status of a Booking. |
| Booking Details | Discarded | Attribute | Booking details belong to the Booking class. |
| Booking Status | Discarded | Attribute | Status is an attribute of Booking. |
| Availability | Discarded | Attribute | Availability is represented as information associated with TimeSlot and ServiceProvider. |
| Service Selection Page | Discarded | Implementation/UI-specific | It represents a user-interface element rather than a domain object. |
| Booking Request | Discarded | Redundant | A booking request is represented by a Booking object. |
| Service List | Discarded | Attribute | A service list is a collection of Service objects rather than a separate domain class. |
| Service Availability | Discarded | Attribute | Availability is information associated with a Service or ServiceProvider. |
| Main Menu | Discarded | Implementation/UI-specific | It is a user-interface element. |
| Issue | Discarded | Irrelevant | The issue is only a reason for a service not being completed and is not a persistent domain entity. |

---

## 7. Final Surviving Classes

The final surviving domain classes are:

- Customer
- ServiceProvider
- Admin
- Service
- Booking
- TimeSlot

These classes are used in the CRC cards, domain class diagram, and object diagram.