## UC-01: Book Service

**Primary Actor:**  
Customer

**Stakeholders:**
- Customer — wants to book a required home service at a convenient time.
- Service Provider — wants to receive valid service requests.
- Admin — wants bookings to be properly recorded and managed.

**Preconditions:**
1. Customer is registered and logged into the system.
2. The required service is available in the system.
3. Service providers are available for the selected service.

**Postconditions:**
1. A booking is created successfully.
2. The booking is stored in the system.
3. The booking status is set to **Pending/Confirmed**.
4. The customer can view the booking details.

**Trigger:**  
The customer selects a service and chooses the **Book Service** option.

### Main Flow

1. Customer logs into the system.
2. Customer views the available services.
3. Customer selects the required service.
4. System displays the service details and available time slots.
5. Customer selects a preferred date and time.
6. System checks service provider availability.
7. System displays the booking summary.
8. Customer confirms the booking.
9. System creates and stores the booking.
10. System displays the booking confirmation to the customer.

### Alternate Flows

#### AF1 — Service Provider Not Available

1. System checks availability for the selected date and time.
2. No suitable service provider is available.
3. System informs the customer that the selected slot is unavailable.
4. Customer selects another date/time.
5. System checks availability again.

#### AF2 — Customer Cancels Before Confirmation

1. Customer reviews the booking details.
2. Customer decides not to continue.
3. Customer cancels the booking process.
4. System does not create the booking.
5. Customer is returned to the service selection page.

---

## UC-03: Manage Booking

**Primary Actor:**  
Service Provider

**Stakeholders:**
- Service Provider — wants to accept and manage assigned service bookings.
- Customer — wants the service to be completed as scheduled.
- Admin — wants to monitor and manage bookings on the platform.

**Preconditions:**
1. Service Provider is registered and logged into the system.
2. Service Provider has access to the relevant service.
3. At least one booking request is available.

**Postconditions:**
1. Booking status is updated.
2. Customer can see the updated booking status.
3. The system maintains the latest booking information.

**Trigger:**  
Service Provider receives or opens a booking request.

### Main Flow

1. Service Provider logs into the system.
2. Service Provider opens the **Manage Bookings** section.
3. System displays available booking requests.
4. Service Provider selects a booking.
5. System displays the booking details.
6. Service Provider accepts the booking.
7. System changes the booking status to **Confirmed**.
8. Customer can view the updated status.
9. Service Provider performs the requested service.
10. Service Provider updates the booking status to **Completed**.
11. System stores the final booking status.

### Alternate Flows

#### AF1 — Service Provider Rejects Booking

1. Service Provider opens a booking request.
2. Service Provider chooses **Reject Booking**.
3. System changes the booking status to **Rejected**.
4. System records the rejection.
5. Customer can view the updated booking status.

#### AF2 — Service Cannot Be Completed

1. Service Provider accepts the booking.
2. An unexpected issue prevents completion of the service.
3. Service Provider updates the booking status accordingly.
4. System stores the updated status.
5. Customer is informed of the change.