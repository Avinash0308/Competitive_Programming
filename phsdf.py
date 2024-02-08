from typing import Optional


class Caller:
    def _init_(self, name: str):
        self.name = name


class CommunicationException(Exception):
    pass


class CommsHandlerABC:
    def connect(self, user1: Caller, user2: Caller) -> str:
        pass

    def hangup(self, user1: Caller, user2: Caller) -> str:
        pass

    def clear_all(self) -> None:
        pass


class CommsHandler(CommsHandlerABC):
    def _init_(self):
        self.connected_users = set()

    def connect(self, user1: Caller, user2: Caller) -> str:
        if user1 == user2:
            raise CommunicationException(f"{user1.name} cannot connect with {user2.name}")

        if (user1, user2) in self.connected_users or (user2, user1) in self.connected_users:
            raise CommunicationException("Connection in use. Please try later")

        self.connected_users.add((user1, user2))
        return f"Connection established between {user1.name} and {user2.name}"

    def hangup(self, user1: Caller, user2: Caller) -> str:
        if user1 == user2:
            raise CommunicationException(f"{user1.name} cannot hangup with {user2.name}")

        if (user1, user2) in self.connected_users:
            self.connected_users.remove((user1, user2))
            return f"{user1.name} and {user2.name} are disconnected"
        elif (user2, user1) in self.connected_users:
            self.connected_users.remove((user2, user1))
            return f"{user1.name} and {user2.name} are disconnected"
        else:
            raise CommunicationException(f"{user1.name} and {user2.name} not found in the communication channel")

    def clear_all(self) -> None:
        self.connected_users.clear()


# Example usage:

# Create Caller instances
caller1 = Caller("Alice")
caller2 = Caller("Bob")
caller3 = Caller("Charlie")

# Create CommsHandler instance
comms_handler = CommsHandler()

# Connect callers
print(comms_handler.connect(caller1, caller2))  # Connection established between Alice and Bob

# Try connecting the same users (should raise an exception)
try:
    print(comms_handler.connect(caller1, caller2))
except CommunicationException as e:
    print(e)  # Connection in use. Please try later

# Hang up
print(comms_handler.hangup(caller1, caller2))  # Alice and Bob are disconnected

# Try hanging up non-communicating users (should raise an exception)
try:
    print(comms_handler.hangup(caller1, caller2))
except CommunicationException as e:
    print(e)  # Alice and Bob not found in the communication channel

# Clear all connections
comms_handler.clear_all()       