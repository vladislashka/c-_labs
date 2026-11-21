#include <iostream>
#include <cstdint>
using namespace std;

enum class OrderStatus : uint8_t {
    Created,
    Paid,
    Shipped,
    Delivered,
    Cancelled
};

struct Order {
    int id;
    double totalPrice;
    OrderStatus status;
};

bool canChangeStatus(OrderStatus from, OrderStatus to) {
    switch (from) {
        case OrderStatus::Created:
            return to == OrderStatus::Paid ||
                   to == OrderStatus::Cancelled;
        case OrderStatus::Paid:
            return to == OrderStatus::Shipped ||
                   to == OrderStatus::Cancelled;
        case OrderStatus::Shipped:
            return to == OrderStatus::Delivered;
        case OrderStatus::Delivered:
        case OrderStatus::Cancelled:
            return false;
    }
    return false;
}

bool changeStatus(Order& order, OrderStatus newStatus) {
    if (!canChangeStatus(order.status, newStatus)) {
        return false;
    }
    order.status = newStatus;
    return true;
}

const char* statusToString(OrderStatus status) {
    switch (status) {
        case OrderStatus::Created:   return "Created";
        case OrderStatus::Paid:      return "Paid";
        case OrderStatus::Shipped:   return "Shipped";
        case OrderStatus::Delivered: return "Delivered";
        case OrderStatus::Cancelled: return "Cancelled";
    }
    return "Unknown";
}

int main() {
    Order order = {101, 2500.0, OrderStatus::Created};
    cout << "Order #" << order.id << endl;
    cout << "Price: " << order.totalPrice << endl;
    cout << "Initial status: "
         << statusToString(order.status) << endl;
    if (changeStatus(order, OrderStatus::Paid)) {
        cout << "New status: "
             << statusToString(order.status) << endl;
    }
    if (changeStatus(order, OrderStatus::Shipped)) {
        cout << "New status: "
             << statusToString(order.status) << endl;
    }
    // Попытка отменить уже отправленный заказ
    if (!changeStatus(order, OrderStatus::Cancelled)) {
        cout << "Cancellation denied!" << endl;
    }
    if (changeStatus(order, OrderStatus::Delivered)) {
        cout << "New status: "
             << statusToString(order.status) << endl;
    }
    return 0;
}
