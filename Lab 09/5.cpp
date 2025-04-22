#include <iostream>
using namespace std;

class Shipment
{
protected:
    string trackingNumber;
    double weight;

public:
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}

    void setTrackingNumber(const string &number)
    {
        trackingNumber = number;
    }

    void setWeight(double w)
    {
        weight = w;
    }
};

class AirFreight : public Shipment
{
public:
    void estimateDeliveryTime() override
    {
        cout << "Estimated Delivery Time: 3 to 5 days" << endl;
    }

    void showDetails() override
    {
        cout << "Shipment Type: Air Freight" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

class GroundShipment : public Shipment
{
public:
    void estimateDeliveryTime() override
    {
        cout << "Estimated Delivery Time: 7 to 10 days" << endl;
    }

    void showDetails() override
    {
        cout << "Shipment Type: Ground Shipment" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main()
{
    AirFreight airShipment;
    GroundShipment groundShipment;

    airShipment.setTrackingNumber("AF768392");
    airShipment.setWeight(12.7);

    groundShipment.setTrackingNumber("GS512947");
    groundShipment.setWeight(28.4);

    Shipment *shipments[2];
    shipments[0] = &airShipment;
    shipments[1] = &groundShipment;

    for (int i = 0; i < 2; i++)
    {
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
    }
    cout << endl;
    return 0;
}
