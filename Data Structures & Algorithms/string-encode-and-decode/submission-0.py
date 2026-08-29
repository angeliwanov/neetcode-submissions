class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:            
            for ch in s:
                encoded += chr((ord(ch) + 17)%256)
            encoded += chr(257)
        return encoded            

    def decode(self, s: str) -> List[str]:
        decoded_list = []
        decoded_str = ""
        for ch in s:
            if ord(ch) == 257:
                decoded_list.append(decoded_str)
                decoded_str = ""
            else:
                decoded_str += chr((ord(ch) - 17)%256)
        return decoded_list
        