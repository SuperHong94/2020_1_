from urllib.parse import urlparse
url="http://search.naver.com/search.naver?where=nexearch&query=python&sm=top_hty&fbm=1"
parts=urlparse(url)
print(parts)
print(parts.path)