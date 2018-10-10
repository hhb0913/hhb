package pojo;

public class Port {

	private String port_number;
	private String receive_packets;
	private String transmit_packets;
	private String receive_bytes;
	private String transmit_bytes;
	private String receive_dropped;
	private String transmit_dropped;
	private String receive_errors;
	private String transmit_errors;
	private String receive_frame_errors;
	private String receive_overrun_errors;
	private String receive_CRC_errors;
	private String collisions;
	private String duration_sec;
	private String duration_nsec;
	
	
	
	public String getPort_number() {
		return port_number;
	}






	public void setPort_number(String port_number) {
		this.port_number = port_number;
	}






	public String getReceive_packets() {
		return receive_packets;
	}






	public void setReceive_packets(String receive_packets) {
		this.receive_packets = receive_packets;
	}






	public String getTransmit_packets() {
		return transmit_packets;
	}






	public void setTransmit_packets(String transmit_packets) {
		this.transmit_packets = transmit_packets;
	}






	public String getReceive_bytes() {
		return receive_bytes;
	}






	public void setReceive_bytes(String receive_bytes) {
		this.receive_bytes = receive_bytes;
	}






	public String getTransmit_bytes() {
		return transmit_bytes;
	}






	public void setTransmit_bytes(String transmit_bytes) {
		this.transmit_bytes = transmit_bytes;
	}






	public String getReceive_dropped() {
		return receive_dropped;
	}






	public void setReceive_dropped(String receive_dropped) {
		this.receive_dropped = receive_dropped;
	}






	public String getTransmit_dropped() {
		return transmit_dropped;
	}






	public void setTransmit_dropped(String transmit_dropped) {
		this.transmit_dropped = transmit_dropped;
	}






	public String getReceive_errors() {
		return receive_errors;
	}






	public void setReceive_errors(String receive_errors) {
		this.receive_errors = receive_errors;
	}






	public String getTransmit_errors() {
		return transmit_errors;
	}






	public void setTransmit_errors(String transmit_errors) {
		this.transmit_errors = transmit_errors;
	}






	public String getReceive_frame_errors() {
		return receive_frame_errors;
	}






	public void setReceive_frame_errors(String receive_frame_errors) {
		this.receive_frame_errors = receive_frame_errors;
	}






	public String getReceive_overrun_errors() {
		return receive_overrun_errors;
	}






	public void setReceive_overrun_errors(String receive_overrun_errors) {
		this.receive_overrun_errors = receive_overrun_errors;
	}






	public String getReceive_CRC_errors() {
		return receive_CRC_errors;
	}






	public void setReceive_CRC_errors(String receive_CRC_errors) {
		this.receive_CRC_errors = receive_CRC_errors;
	}






	public String getCollisions() {
		return collisions;
	}






	public void setCollisions(String collisions) {
		this.collisions = collisions;
	}






	public String getDuration_sec() {
		return duration_sec;
	}






	public void setDuration_sec(String duration_sec) {
		this.duration_sec = duration_sec;
	}






	public String getDuration_nsec() {
		return duration_nsec;
	}






	public void setDuration_nsec(String duration_nsec) {
		this.duration_nsec = duration_nsec;
	}






	@Override
	public String toString() {
		return JsonUtils.toJson(this);
	}
}
